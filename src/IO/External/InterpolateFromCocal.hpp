#pragma once

#include <cstddef>
#include <mutex>
#include <string>

#include "DataStructures/DataVector.hpp"
#include "DataStructures/Tensor/Tensor.hpp"
#include "PointwiseFunctions/GeneralRelativity/Tags.hpp"
#include "PointwiseFunctions/Hydro/Tags.hpp"
#include "Utilities/TMPL.hpp"
#include "Utilities/TaggedTuple.hpp"


namespace io {

// List of tags supplied by COCAL initial data
using cocal_tags = tmpl::list<gr::Tags::Lapse<DataVector>,
                              gr::Tags::Shift<DataVector, 3>,
                              gr::Tags::SpatialMetric<DataVector, 3>,
                              gr::Tags::ExtrinsicCurvature<DataVector, 3>,
                              hydro::Tags::RestMassDensity<DataVector>,
                              hydro::Tags::SpecificInternalEnergy<DataVector>,
                              hydro::Tags::Pressure<DataVector>,
                              hydro::Tags::LorentzFactor<DataVector>,
                              hydro::Tags::SpatialVelocity<DataVector, 3>>;

/*!
 * \brief Interpolate numerical COCAL initial data to arbitrary points  
 * \param cocal_lock 
 * \param x Coordinates of points to interpolate to
 * \return Data interpolated to the given points
 */
tuples::tagged_tuple_from_typelist<cocal_tags> interpolate_from_cocal(
    gsl::not_null<std::mutex*> cocal_lock,
    /*const std::string& data_directory,*/
    const tnsr::I<DataVector, 3, Frame::Inertial>& x);

}  // namespace io
