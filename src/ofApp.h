#pragma once

#include "ofMain.h"

#include <CGAL/basic.h>

// includes for defining the Voronoi diagram adaptor
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Voronoi_diagram_2.h>
#include <CGAL/Delaunay_triangulation_adaptation_traits_2.h>
#include <CGAL/Delaunay_triangulation_adaptation_policies_2.h>


class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    // typedefs for defining the adaptor
    typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
    typedef CGAL::Delaunay_triangulation_2 < K > DT;
    typedef CGAL::Delaunay_triangulation_adaptation_traits_2 < DT > AT;
    typedef CGAL::Delaunay_triangulation_caching_degeneracy_removal_policy_2 < DT > AP;
    typedef CGAL::Voronoi_diagram_2 < DT,AT,AP > VD;
    
    // typedef for the result type of the point location
    typedef AT::Site_2 Site_2;
    typedef AT::Point_2 Point_2;
    
    typedef VD::Locate_result Locate_result;
    typedef VD::Vertex_handle Vertex_handle;
    typedef VD::Face_handle Face_handle;
    typedef VD::Halfedge_handle Halfedge_handle;
    typedef VD::Ccb_halfedge_circulator Ccb_halfedge_circulator;
    
    
    const int point_num = 200;
    VD vd;
    vector<Site_2> outerTriangle;
    vector<Site_2> sites;
};
