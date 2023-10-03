#include "hitable_list.hpp"

#include <cstring>
#include <memory>

HitableList::HitableList(const std::vector<Hitable>& list) : list_(list) {}

const std::vector<Hitable>& HitableList::list() const { return list_; }

bool HitableList::Hit(const Ray& ray, float tmin, float tmax,
                      HitRecord& rec) const {
  HitRecord tmp_rec;

  bool hit_anyting = false;

  float closest_so_far = tmax;

  for (auto it = std::cbegin(list_); it != std::cend(list_); ++it) {
    if (it->Hit(ray, tmin, closest_so_far, tmp_rec)) {
      hit_anyting = true;
      closest_so_far = tmp_rec.t;
      rec = tmp_rec;
    }
  }
  return hit_anyting;
}

void HitableList::AddHitable(const Sphere& hitable) {
  list_.push_back(hitable);
}

const int HitableList::NumHitabels() const { return list_.size(); }
