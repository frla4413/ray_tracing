#pragma once

#include "hitable.hpp"

class Sphere : public Hitable {
 public:
  Sphere();
  Sphere(const glm::vec3 &center, float radius);

  bool Hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const;

 private:
  glm::vec3 center_;
  float radius_;
};
