// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     geo_package/all_geo_types.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include <tuple>

#include <sym/pose2.h>
#include <sym/pose3.h>
#include <sym/rot2.h>
#include <sym/rot3.h>
#include <sym/unit3.h>

namespace sym {

template <typename Scalar>
using AllGeoTypes =
    std::tuple<Rot2<Scalar>, Rot3<Scalar>, Pose2<Scalar>, Pose3<Scalar>, Unit3<Scalar>>;

}  // namespace sym
