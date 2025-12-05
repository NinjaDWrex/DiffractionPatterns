use rand::thread_rng;
use rand_distr::{Distribution, Normal};
use std::os::raw::c_float;
#[unsafe(no_mangle)]
pub extern "C" fn generate_angle() -> c_float {
    let mean: c_float = 0.0;
    let sd: c_float = 0.785;
    let dist = Normal::new(mean, sd).unwrap();
    let mut rng = thread_rng();
    dist.sample(&mut rng)
}
