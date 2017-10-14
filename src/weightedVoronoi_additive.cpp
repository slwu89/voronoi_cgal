//
//  weightedVoronoi_additive.cpp
//  voronoi_cgal
//
//  Created by Sean Wu on 10/13/17.
//
//

#include "weightedVoronoi_additive.hpp"

weightedVoronoi_additive::weightedVoronoi_additive(){
    n_nodes = 0;
    std::cout << "object of class weightedVoronoi_additive getting born at memory location: " << this << std::endl;
};

weightedVoronoi_additive::~weightedVoronoi_additive(){
    std::cout << "object of class weightedVoronoi_additive getting killed at memory location: " << this << std::endl;
};

void weightedVoronoi_additive::add_node(const NT &x, const NT &y, const NT &weight){
    nodes.push_back(ApolloniusGraph_Site2(Point_2(x,y),weight));
    voronoi.insert(nodes.back());
    n_nodes++;
};

void weightedVoronoi_additive::add_node_cgal(const ApolloniusGraph_Site2 &n){
    nodes.push_back(n);
    voronoi.insert(n);
    n_nodes++;
};
