#include "save_simulation_data.hpp"


namespace cgmres {

void saveData(const int dim_state, const int dim_control_input, 
              std::ofstream& state_data, std::ofstream& control_input_data, 
              std::ofstream& error_data, const double time_param, 
              const double* state_vec, const double* control_input_vec,
              const double error_norm) {
    if (time_param == 0) { state_data << "t,x,y,psi,u,v,r\n"; }
    state_data << time_param << ",";
    for (int i=0; i<dim_state; i++) {
    state_data << state_vec[i] << ",";
  }
  state_data << "\n";

  if (time_param == 0) { control_input_data << "t,delta,delta_dummy\n"; }
  control_input_data << time_param << ",";
  for (int i=0; i<dim_control_input; i++) {
    control_input_data << control_input_vec[i] << ",";
  }
  control_input_data << "\n";

  if (time_param == 0) { error_data << "t,error\n"; }
  error_data << time_param << ",";
  error_data << error_norm << "\n";
}

} // namespace cgmres