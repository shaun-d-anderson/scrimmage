/*!
 * @file
 *
 * @section LICENSE
 *
 * Copyright (C) 2017 by the Georgia Tech Research Institute (GTRI)
 *
 * This file is part of SCRIMMAGE.
 *
 *   SCRIMMAGE is free software: you can redistribute it and/or modify it under
 *   the terms of the GNU Lesser General Public License as published by the
 *   Free Software Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   SCRIMMAGE is distributed in the hope that it will be useful, but WITHOUT
 *   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 *   License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with SCRIMMAGE.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Kevin DeMarco <kevin.demarco@gtri.gatech.edu>
 * @author Eric Squires <eric.squires@gtri.gatech.edu>
 * @date 31 July 2017
 * @version 0.1.0
 * @brief Brief file description.
 * @section DESCRIPTION
 * A Long description goes here.
 *
 */

#ifndef INCLUDE_SCRIMMAGE_PLUGINS_SENSOR_SIMPLEINS_SIMPLEINS_H_
#define INCLUDE_SCRIMMAGE_PLUGINS_SENSOR_SIMPLEINS_SIMPLEINS_H_

#include <scrimmage/sensor/Sensor.h>

#include <map>
#include <string>
#include <vector>
#include <memory>

namespace scrimmage {

namespace sensor {
class SimpleINS : public scrimmage::Sensor {
 public:
    void init(std::map<std::string, std::string> &params) override;
    bool step() override;

 protected:
    bool gps_fix_;

    PublisherPtr pub_;
    PublisherPtr pub_cep_;
    PublisherPtr pub_seastate_;

    std::vector<std::shared_ptr<std::normal_distribution<double>>> pos_noise_;
    std::vector<std::shared_ptr<std::normal_distribution<double>>> vel_noise_;
    std::vector<std::shared_ptr<std::normal_distribution<double>>> orient_noise_;

    Eigen::Vector3d pos_error_accum_ = Eigen::Vector3d::Zero();
    Eigen::Vector3d vel_Nminus1 = Eigen::Vector3d::Zero();
    Eigen::Vector3d accel_ = Eigen::Vector3d::Zero();

    Eigen::MatrixXd m_;
    bool init_m_ = true;

    double surface_timer_ = 0;
    double prev_time_ = 0;
    double sea_state_gps_;
    double SeaState_;

};
} // namespace sensor
} // namespace scrimmage
#endif // INCLUDE_SCRIMMAGE_PLUGINS_SENSOR_SIMPLEINS_SIMPLEINS_H_
