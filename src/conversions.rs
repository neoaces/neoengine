use std::time::Instant;

pub fn time_ms(timer: Instant) -> f32{
	(timer.elapsed().as_millis() as f32)
}

pub fn secs_to_mil(time: f32) -> f32{
	time * 1000.0
}

pub fn mil_to_secs(time: f32) -> f32 {
	time / 1000.0
}

pub fn mps_to_mpms(time: f32) -> f32 {
	time / 1000.0
}
pub fn mpms_to_mps(time: f32) -> f32{
	time * 1000.0
}