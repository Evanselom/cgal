#ifndef CGAL_DEMO_MESH_3_C3T3_TYPE_H
#define CGAL_DEMO_MESH_3_C3T3_TYPE_H

#include "Polyhedron_type.h"
#if 0
#include "Image_type.h"
#include "implicit_functions/Implicit_function_interface.h"
#endif

#include <CGAL/Mesh_triangulation_3.h>
#include <CGAL/Mesh_complex_3_in_triangulation_3.h>

#include <CGAL/Mesh_3/Robust_intersection_traits_3.h>
#include <CGAL/Polyhedral_mesh_domain_3.h>
#include <CGAL/Polyhedral_mesh_domain_with_features_3.h>
#include <CGAL/Labeled_image_mesh_domain_3.h>

#include <CGAL/tags.h>

#if 0
template <typename K>
struct Wrapper
{
  typedef int return_type;
  typedef typename K::Point_3 Point_3;
  
  Wrapper(const Implicit_function_interface& f) : f_(f) {}
  return_type operator()(const Point_3& p, const bool=true) const
  {
    return (f_(p.x(),p.y(),p.z()) < 0) ? 1 : 0;
  }
  
private:
  const Implicit_function_interface& f_;
};
#endif

typedef CGAL::Triangle_accessor_3<Polyhedron, Kernel> T_accessor;

typedef CGAL::Polyhedral_mesh_domain_with_features_3<
          Kernel, Polyhedron, T_accessor, CGAL::Tag_true> Polyhedral_mesh_domain;
// The last `Tag_true` says the Patch_id type will be int
// until now, in `Image_mesh_domain`, and `Function_mesh_domain`.
// Patch_id is pair<int,int>

#if 0
typedef CGAL::Labeled_image_mesh_domain_3<Image,Kernel>                 Image_mesh_domain;
typedef Wrapper<Kernel>                                                 Function_wrapper;
typedef CGAL::Labeled_mesh_domain_3<Function_wrapper, Kernel>           Function_mesh_domain;
#endif

// Triangulation
#ifdef CGAL_CONCURRENT_MESH_3
  typedef CGAL::Mesh_triangulation_3<Polyhedral_mesh_domain, 
                                     CGAL::Kernel_traits<Polyhedral_mesh_domain>::Kernel,
                                     CGAL::Parallel_tag>::type Tr;
#else
  typedef CGAL::Mesh_triangulation_3<Polyhedral_mesh_domain>::type Tr;
#endif
typedef CGAL::Mesh_complex_3_in_triangulation_3<Tr> C3t3;

// 3D complex

#endif // CGAL_DEMO_MESH_3_C3T3_TYPE_H
