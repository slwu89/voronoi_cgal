//
//  weightedVoronoi_additive.hpp
//  voronoi_cgal
//
//  Created by Sean Wu on 10/13/17.
//
//

#ifndef AWV_HPP
#define AWV_HPP

#include <iostream>
#include <vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// define kernel

#include <CGAL/basic.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel         Kernel;
typedef double                                                      NT;
typedef Kernel::Circle_2                                            Circle_2;
typedef Kernel::Segment_2                                           Segment_2;
typedef Kernel::Vector_2                                            Vector_2;
typedef Kernel::Vector_3                                            Vector_3;
typedef Kernel::Ray_2                                               Ray_2;
typedef Kernel::Iso_rectangle_2                                     Rectangle_2;
typedef Kernel::Point_2                                             Point_2;
typedef CGAL::Bbox_2                                                Bbox_2;


// define graph

// Delunay triangulation; dual of graph is a Voronoi diagram
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Voronoi_diagram_2.h>

// Apollonius graph is the dual of the additively weighted Voronoi diagram
#include <CGAL/Apollonius_graph_2.h>
#include <CGAL/Apollonius_graph_traits_2.h>
#include <CGAL/Apollonius_graph_adaptation_traits_2.h>
#include <CGAL/Apollonius_graph_adaptation_policies_2.h>


// graph
typedef CGAL::Apollonius_graph_traits_2<Kernel>                                                             ApolloniusGraph_Traits;
typedef CGAL::Apollonius_site_2<Kernel>                                                                     ApolloniusGraph_Site2;
typedef CGAL::Apollonius_graph_2<ApolloniusGraph_Traits>                                                    ApolloniusGraph;

typedef CGAL::Apollonius_graph_adaptation_traits_2<ApolloniusGraph>                                         ApolloniusGraph_AdaptTraits;
typedef CGAL::Apollonius_graph_caching_degeneracy_removal_policy_2<ApolloniusGraph>                         ApolloniusGraph_RemovePolicy;
typedef CGAL::Voronoi_diagram_2<ApolloniusGraph,ApolloniusGraph_AdaptTraits,ApolloniusGraph_RemovePolicy>   ApolloniusGraph_VoronoiDiagram;

// site
typedef ApolloniusGraph_Site2::Point_2                                                                      Site2_Point2;
typedef ApolloniusGraph_Site2::Weight                                                                       Site2_Weight;

// data extraction
typedef ApolloniusGraph_VoronoiDiagram::Locate_result                                                       Locate_result;
typedef ApolloniusGraph_VoronoiDiagram::Vertex_handle                                                       Vertex_handle;
typedef ApolloniusGraph_VoronoiDiagram::Face_handle                                                         Face_handle;
typedef ApolloniusGraph_VoronoiDiagram::Face                                                                Face;
typedef ApolloniusGraph_VoronoiDiagram::Halfedge_handle                                                     Halfedge_handle;
typedef ApolloniusGraph_VoronoiDiagram::Halfedge                                                            Halfedge;
typedef ApolloniusGraph_VoronoiDiagram::Face_iterator                                                       Face_iterator;
typedef ApolloniusGraph_VoronoiDiagram::Ccb_halfedge_circulator                                             Ccb_halfedge_circulator;

class weightedVoronoi_additive {
public:
    weightedVoronoi_additive();
    ~weightedVoronoi_additive();

    void                                                            add_node(const NT &x, const NT &y, const NT &weight);
    void                                                            add_node_cgal(const ApolloniusGraph_Site2 &n);

    int                                                             get_n_nodes(){return n_nodes;};
    void                                                            set_n_nodes(const int& n){n_nodes = n;};

    // shouldn't be public, but don't know how to traverse arrangement otherwise
    ApolloniusGraph                                                 voronoi;
    std::vector<ApolloniusGraph_Site2>                              nodes;
    int                                                             n_nodes;
private:

};




//typedef CGAL::Apollonius_graph_traits_2<Kernel>                     AWTraits;
//typedef CGAL::Apollonius_graph_2<AWTraits>                          Apollonius_graph;
//typedef Apollonius_graph::Site_2                                    Site_2;
//
//// results
//typedef Apollonius_graph::Vertex_handle Vertex_handle;
//typedef Apollonius_graph::Face_handle Face_handle;
//
//class weightedVoronoi_additive {
//public:
//    weightedVoronoi_additive();
//    ~weightedVoronoi_additive();
//    
//    void                                                            add_node(const NT &x, const NT &y, const NT &weight);
//    void                                                            add_node_cgal(const Site_2 &n);
//    
//    int                                                             get_n_nodes(){return n_nodes;};
//    void                                                            set_n_nodes(const int& n){n_nodes = n;};
//    
//    // shouldn't be public, but don't know how to traverse arrangement otherwise    
//    Apollonius_graph                                                voronoi;
//    std::vector<Site_2>                                             nodes;
//    int                                                             n_nodes;
//private:
//
//};



#endif /* weightedVoronoi_additive_hpp */
