/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          http://www.mrpt.org/                             |
   |                                                                           |
   | Copyright (c) 2005-2017, Individual contributors, see AUTHORS file        |
   | See: http://www.mrpt.org/Authors - All rights reserved.                   |
   | Released under BSD License. See details in http://www.mrpt.org/License    |
   +---------------------------------------------------------------------------+ */
#pragma once

#include <mrpt/kinematics/CVehicleVelCmd.h>

namespace mrpt
{
namespace kinematics
{

	/** Kinematic model for Ackermann-like or differential-driven vehicles.
	 *
	 * \ingroup mrpt_kinematics_grp
	 */
	class KINEMATICS_IMPEXP CVehicleVelCmd_DiffDriven : public CVehicleVelCmd
	{
		DEFINE_SERIALIZABLE(CVehicleVelCmd_DiffDriven)
	public:
		double lin_vel; //!< Linear velocity (m/s)
		double ang_vel; //!< Angular velocity (rad/s)

		CVehicleVelCmd_DiffDriven();
		virtual ~CVehicleVelCmd_DiffDriven();
		size_t getVelCmdLength() const override;
		std::string getVelCmdDescription(const int index) const override;
		double getVelCmdElement(const int index) const  override;
		void setVelCmdElement(const int index, const double val) override;
		bool isStopCmd() const override;
		void setToStop() override;

		/** See docs of method in base class. The implementation for differential-driven robots of this method
		* just multiplies all the components of vel_cmd times vel_scale, which is appropriate
		*  for differential-driven kinematic models (v,w).
		*/
		void cmdVel_scale(double vel_scale) override;

		/** See base class docs.
		 * Tecognizes these parameters: `robotMax_V_mps`, `robotMax_W_degps` */
		double cmdVel_limits(const mrpt::kinematics::CVehicleVelCmd &prev_vel_cmd, const double beta, const TVelCmdParams &params)  override;

	private:
		double filter_max_vw(double &v, double &w, const TVelCmdParams &p);
	};
	DEFINE_SERIALIZABLE_POST_CUSTOM_BASE_LINKAGE(CVehicleVelCmd_DiffDriven, CVehicleVelCmd, KINEMATICS_IMPEXP)

	} // End of namespace
} // End of namespace
