use std::time::Instant;

pub fn mil_to_secs(timer: Instant) -> f32{
	(timer.elapsed().as_millis() as f32) / 1000.0
}