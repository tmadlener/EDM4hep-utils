#ifndef EDM4HEP_UTILS_KINEMATICS_H
#define EDM4HEP_UTILS_KINEMATICS_H

#include "Math/Vector4D.h"

#include <cmath>

namespace edm4hep {
/**
 * A LorentzVector with (px, py, pz) and M
 */
using LorentzVectorM = ROOT::Math::PxPyPzMVector;

/**
 * A LorentzVector with (px, py, pz) and E
 */
using LorentzVectorE = ROOT::Math::PxPyPzEVector;

namespace utils {

/**
 * Get the transverse momentum from a Particle
 */
template<typename ParticleT>
inline float pT(ParticleT const& p) {
  return std::sqrt(p.getMomentum()[0] * p.getMomentum()[0] + p.getMomentum()[1] * p.getMomentum()[1]);
}

/**
 * Get the transverse momentum from a Particle
 */
template<typename ParticleT>
inline float pt(ParticleT const& p) {
  return pT(p);
}

/**
 * Get the total momentum from a Particle
 */
template<typename ParticleT>
inline float p(ParticleT const& part) {
  const auto mom = part.getMomentum();
  return std::sqrt(mom[0]*mom[0] + mom[1]*mom[1] + mom[2]*mom[2]);
}

namespace impl {
/**
 * Tag struct for getting 4-momenta with momentum + mass
 */
struct UseMassTag {
  using type = ::edm4hep::LorentzVectorM;
};

/**
 * Tag struct for getting 4-moment with momentum + energy
 */
struct UseEnergyTag {
  using type = ::edm4hep::LorentzVectorE;
};

/**
 * Tag-dispatched implementation for getting the 4-momentum from a particle
 * according to the desired type.
 */
template<typename ParticleT, typename LorentzVectorTypeTag>
inline typename LorentzVectorTypeTag::type p4(ParticleT const& part, LorentzVectorTypeTag*) {
  const auto mom = part.getMomentum();
  if constexpr(std::is_same_v<typename LorentzVectorTypeTag::type, LorentzVectorM>) {
    return LorentzVectorM{mom[0], mom[1], mom[2], part.getMass()};
  }
  if constexpr(std::is_same_v<typename LorentzVectorTypeTag::type, LorentzVectorE>) {
    return LorentzVectorE{mom[0], mom[1], mom[2], part.getEnergy()};
  }
}
} // namespace impl

/**
 * Static tag to select the mass in 4 momentum vectors
 */
constexpr static impl::UseMassTag UseMass;

/**
 * Static tag to select the energy in 4 momentum vectors
 */
constexpr static impl::UseEnergyTag UseEnergy;

/**
 * Get the 4 momentum vector from a Particle. By default using the momentum and
 * the mass, but can be switched to using the energy when using the UseEnergy as
 * second argument.
 */
template<typename ParticleT, typename LorentzVectorTag=impl::UseMassTag>
inline typename LorentzVectorTag::type p4(ParticleT const& part, LorentzVectorTag tag=UseMass) {
  return impl::p4(part, &tag);
}


}} // namespace edm4hep::utils


#endif
