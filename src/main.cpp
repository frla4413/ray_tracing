#include <glm/vec3.hpp>
#include <iostream>
#include <limits>

#include "hitable.hpp"
#include "hitable_list.hpp"
#include "ray.hpp"
#include "sphere.hpp"

/*
 * Gör vector med type (ex sphere), argument ()
 */

glm::vec3 Color(const Ray& r, const HitableList& world) {
  HitRecord rec;

  if (world.Hit(r, 0.f, std::numeric_limits<float>::max(), rec)) {
    return 0.5f *
           glm::vec3(rec.normal[0] + 1, rec.normal[1] + 1, rec.normal[2] + 1);
  } else {
    auto unit_direction = MakeUnitVector(r.direction());
    float t = 0.5 * (unit_direction[1] + 1.f);
    return (1.f - t) * glm::vec3(1.f, 1.f, 1.f) + t * glm::vec3(0.5, 0.7, 1.f);
  }
}

int main() {
  int nx = 200;
  int ny = 100;

  std::cout << "P3\n" << nx << " " << ny << "\n255\n";
  glm::vec3 lower_left_corner{-2.0, -1.0, -1.0};
  glm::vec3 horizontal{4.0, 0.0, 0.0};
  glm::vec3 vertical{0.0, 2.0, 0.0};
  glm::vec3 origin{0.0, 0.0, 0.0};

  Sphere s1{glm::vec3(0.f, 0.f, -1.f), 0.5f};
  Sphere s2{glm::vec3(0.f, -100.5f, -1.f), 100.f};
  std::vector<Hitable> spheres;
  spheres.push_back(s1);
  spheres.push_back(s2);

  Hitable* s3 = &s1;
  Hitable* s4 = &s2;

  std::vector<Hitable*> shapes{s3, s4};

  for (int j = ny - 1; j >= 0; --j) {
    for (int i = 0; i < nx; ++i) {
      float u = float(i) / float(nx);
      float v = float(j) / float(ny);

      Ray r{origin, lower_left_corner + u * horizontal + v * vertical};
      glm::vec3 col{Color(r, list)};

      int ir = int(255.99 * col[0]);
      int ig = int(255.99 * col[1]);
      int ib = int(255.99 * col[2]);

      std::cout << ir << " " << ig << " " << ib << "\n";
    }
  }

  return 0;
}
