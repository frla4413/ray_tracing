#include "ray.hpp"

#include <math.h>

#include <glm/geometric.hpp>

Ray::Ray(const glm::vec3& origin, const glm::vec3& direction)
    : origin_(origin), direction_(direction){};

const glm::vec3 Ray::origin() const { return origin_; }

const glm::vec3 Ray::direction() const { return direction_; }

glm::vec3 PointAtParameter(const Ray& ray, float t) {
  return ray.origin() + t * ray.direction();
}

float Magnitude(const glm::vec3& v) {
  auto magnitude = 0.f;
  for (int i = 0; i < v.length(); ++i) {
    magnitude += v[i] * v[i];
  }
  return std::sqrt(magnitude);
}

glm::vec3 MakeUnitVector(const glm::vec3& v) {
  auto v_nrm = v;
  v_nrm /= Magnitude(v);
  return v_nrm;
}

// glm::vec3 Color(const Ray& r) {
//   float t = HitSpehere(glm::vec3(0.f, 0.f, -1.f), 0.5, r);
//
//   if (t > 0.f) {
//     glm::vec3 vec = PointAtParameter(r, t) - glm::vec3(0.f, 0.f, -1.f);
//     glm::vec3 N = MakeUnitVector(vec);
//     return 0.5f * glm::vec3(N[0] + 1, N[1] + 1, N[2] + 1);
//   }
//
//   auto unit_direction = MakeUnitVector(r.direction());
//   t = 0.5 * (unit_direction[1] + 1);
//
//   return (1.f - t) * glm::vec3(1, 1, 1) + t * glm::vec3(0.5f, 0.7f, 1.0f);
// }

/*
 * True if Ray r passes throug the sphere using the disciminant.
 * If the ray passes the sphere 2 times, the discriminant is positive.
 */
float HitSpehere(const glm::vec3 center, float radius, const Ray& r) {
  glm::vec3 origin_center = r.origin() - center;
  float a = glm::dot(r.direction(), r.direction());
  float b = 2 * glm::dot(origin_center, r.direction());
  float c = glm::dot(origin_center, origin_center) - radius * radius;
  float discriminant = b * b - 4 * a * c;

  if (discriminant < 0) return -1;

  return (-b - std::sqrt(discriminant)) / 2.f / a;
}
