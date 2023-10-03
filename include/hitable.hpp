#pragma once

#include <string>

#include "ray.hpp"

struct HitRecord {
  float t;
  glm::vec3 p;
  glm::vec3 normal;
};

class Hitable {
 public:
  Hitable(){};

  virtual bool Hit(const Ray& r, float t_min, float t_max,
                   HitRecord& rec) const = 0;

  const virtual std::string HitableType() const;

 private:
};
