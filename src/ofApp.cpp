#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    auto v = ofVec2f(ofGetWidth()/2.0, ofGetHeight()/2.0);
    
    float r = v.length();
    float rcst = r/sin(PI/6);
    float rcot = r/tan(PI/6);
    
    outerTriangle.push_back(Site_2(v.x, v.y - rcst));
    outerTriangle.push_back(Site_2(v.x - rcot, v.y + r));
    outerTriangle.push_back(Site_2(v.x + rcot, v.y + r));
    for(auto v: outerTriangle){
        vd.insert(v);
    }
    
    for(int i = 0; i < point_num; ++i){
        sites.push_back(Site_2(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())));
        vd.insert(sites.back());
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofBeginShape();
    for(auto v: outerTriangle){
        ofVertex(v.x(), v.y());
    }
    ofEndShape(OF_CLOSE);
    ofFill();
    for(int i = 0; i < point_num; i++){
        // Pick up Point
        Point_2 p(sites[i].x(), sites[i].y());
        ofDrawEllipse(p.x(), p.y(), 5, 5);
        
        // Get Voronoi locate result for p
        Locate_result lr = vd.locate(p);
        
        // Get face handle
        Face_handle* f = boost::get< Face_handle >(&lr);
        
        // Get halfedge from face handle
        Ccb_halfedge_circulator ec_start = (*f)->outer_ccb();
        
        // Store start-halfedge
        Ccb_halfedge_circulator ec = ec_start;
        
        do {
            // Edge is availabe?
            if(ec->has_source()){
                // Voronoi Edge's start point
                double vxs = ec->source()->point().x();
                double vys = ec->source()->point().y();
                if(ec->has_target()){
                    // Voronoi Edge's target point
                    double vxt = ec->target()->point().x();
                    double vyt = ec->target()->point().y();
                    
                    // Draw
                    ofDrawLine(ofPoint(vxs, vys), ofPoint(vxt, vyt));
                }
            }
            else{
                // Edge target Point is infinity
                std::cout << "inf" << std::endl;
            }
        } while ( ++ec != ec_start );
        
    }
}