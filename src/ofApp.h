#pragma once

#include "ofMain.h"

#include "weightedVoronoi_additive.hpp"

//#include <CGAL/basic.h>
//
//// includes for defining the Voronoi diagram adaptor
//#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
//#include <CGAL/Delaunay_triangulation_2.h>
//#include <CGAL/Voronoi_diagram_2.h>
//#include <CGAL/Delaunay_triangulation_adaptation_traits_2.h>
//#include <CGAL/Delaunay_triangulation_adaptation_policies_2.h>

#include <CGAL/Delaunay_triangulation_2.h>
#include <iterator>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef K::Iso_rectangle_2 Iso_rectangle_2;
typedef K::Segment_2 Segment_2;
typedef K::Ray_2 Ray_2;
typedef K::Line_2 Line_2;
typedef CGAL::Delaunay_triangulation_2<Kernel> Delaunay_triangulation_2;

//A class to recover Voronoi diagram from stream.
//Rays, lines and segments are cropped to a rectangle
//so that only segments are stored
struct Cropped_voronoi_from_delaunay{
    std::list<Segment_2> m_cropped_vd;
    Iso_rectangle_2 m_bbox;
    Cropped_voronoi_from_delaunay(const Iso_rectangle_2& bbox):m_bbox(bbox){}
    template <class RSL>
    void crop_and_extract_segment(const RSL& rsl){
        CGAL::Object obj = CGAL::intersection(rsl,m_bbox);
        const Segment_2* s=CGAL::object_cast<Segment_2>(&obj);
        if (s) m_cropped_vd.push_back(*s);
    }
    void operator<<(const Ray_2& ray) { crop_and_extract_segment(ray); }
    void operator<<(const Line_2& line) { crop_and_extract_segment(line); }
    void operator<<(const Segment_2& seg){ crop_and_extract_segment(seg); }
};



class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
//    // typedefs for defining the adaptor
//    typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
//    typedef CGAL::Delaunay_triangulation_2 < K > DT;
//    typedef CGAL::Delaunay_triangulation_adaptation_traits_2 < DT > AT;
//    typedef CGAL::Delaunay_triangulation_caching_degeneracy_removal_policy_2 < DT > AP;
//    typedef CGAL::Voronoi_diagram_2 < DT,AT,AP > VD;
//    
//    // typedef for the result type of the point location
//    typedef AT::Site_2 Site_2;
//    typedef AT::Point_2 Point_2;
//    
//    typedef VD::Locate_result Locate_result;
//    typedef VD::Vertex_handle Vertex_handle;
//    typedef VD::Face_handle Face_handle;
//    typedef VD::Halfedge_handle Halfedge_handle;
//    typedef VD::Ccb_halfedge_circulator Ccb_halfedge_circulator;
//    
//    
//    
//    const int initial_points = 200;
//    int       current_points;
//    VD vd;
//    vector<Site_2> outerTriangle;
//    vector<Site_2> sites;
    
    
    
    const double                                    MAX_WEIGHT = 100;
    const int                                       initial_nodes = 200;
    weightedVoronoi_additive                        diagram;
    std::vector<ApolloniusGraph_Site2>              outerTriangle;
    
};
