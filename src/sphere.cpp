#include "sphere.hpp"

#include <math.h>

#include <glm/geometric.hpp>

#include "ray.hpp"

Sphere::Sphere(const glm::vec3 &center, float radius)
    : center_(center), radius_(radius) {}

bool Sphere::Hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const {
  glm::vec3 origin_center = r.origin() - center_;
  float a = glm::dot(r.direction(), r.direction());
  float b = glm::dot(origin_center, r.direction());
  float c = glm::dot(origin_center, origin_center) - radius_ * radius_;
  float discriminant = b * b - a * c;

  if (discriminant > 0) {
    float tmp = (-b - std::sqrt(discriminant)) / a;

    if (tmp < t_max && tmp > t_min) {
      rec.t = tmp;
      rec.p = PointAtParameter(r, rec.t);
      rec.normal = (rec.p - center_) / radius_;

      return true;
    }
    tmp = (-b + std::sqrt(discriminant)) / a;
    if (tmp < t_max && tmp > t_min) {
      rec.t = tmp;
      rec.p = PointAtParameter(r, rec.t);
      rec.normal = (rec.p - center_) / radius_;

      return true;
    }
  }
  return false;
}
