#pragma once
#include <glm/vec3.hpp>

class Ray {
 public:
  Ray();
  Ray(Ray&&) = default;
  Ray(const Ray&) = default;
  Ray& operator=(Ray&&) = default;
  Ray& operator=(const Ray&) = default;
  ~Ray() = default;

  Ray(const glm::vec3& origin, const glm::vec3& direction);
  const glm::vec3 origin() const;
  const glm::vec3 direction() const;

 private:
  glm::vec3 origin_;
  glm::vec3 direction_;
};

glm::vec3 PointAtParameter(const Ray& ray, float t);

void Print(const Ray& ray);
void Print(const glm::vec3& v);

float Magnitude(const glm::vec3& v);
glm::vec3 MakeUnitVector(const glm::vec3& v);
// glm::vec3 Color(const Ray& r);

float HitSpehere(const glm::vec3 center, float radius, const Ray& r);
