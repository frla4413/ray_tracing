#pragma once

#include <memory>
#include <vector>

#include "memory"
#include "sphere.hpp"

class HitableList : public Hitable {
 public:
  HitableList(){};
  HitableList(const std::vector<Hitable>& list);

  const std::vector<Hitable>& list() const;
  bool Hit(const Ray& ray, float tmin, float tmax, HitRecord& rec) const;

  void AddHitable(const Sphere& hitable);

  const int NumHitabels() const;

 private:
  std::vector<Hitable> list_;
  //  std::vector<std::unique_ptr<Hitable>> list_;
};
