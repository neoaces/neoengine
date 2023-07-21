use crate::{vector::Vec2, conversions::{secs_to_mil, mps_to_mpms, mpms_to_mps}};
use core::fmt::Debug;

pub trait Moveable {
	// type Body;
	fn apply(&mut self, ms: f32) -> Result<(), CalculationError>;
	fn print(&self);
	fn to_string(&self) -> String;
}

impl Debug for dyn Moveable {
    fn fmt(&self, f: &mut core::fmt::Formatter<'_>) -> core::fmt::Result {
        write!(f, "Series{{{}}}", self.to_string())
    }
}

#[derive(Debug)]
pub struct SquareBody {
	pub x: f32,
	pub y: f32,
	pub velocity: Vec2,
	pub acc: Vec2 // TODO: Create test for acceleration
}
#[derive(Debug)]
pub struct CalculationError;

impl Moveable for SquareBody {
	fn apply(&mut self, ms: f32) -> Result<(), CalculationError> {
		// let mut app_velocity = self.acc;
		// app_velocity.scale(ms).unwrap();
		// self.velocity = self.velocity + app_velocity;
		
		// X
		self.x += self.velocity.x * ms;
		// Y
		self.y += self.velocity.y * ms;
		Ok(())
	}

	fn print(&self) {
		println!("Position, x: {:.3}, y: {:.3} | Velocity, x: {}m/s, y: {}m/s | Acceleration: {}m/s", self.x, self.y, mpms_to_mps(self.velocity.x), mpms_to_mps(self.velocity.y), mpms_to_mps(self.acc.magnitude()));
	}

	fn to_string(&self) -> String {
		let x  = format!("Velocity, x: {}, y: {}", self.x, self.y);
		x
	}

}

impl SquareBody {
	pub fn new(x: f32, y: f32, vx: f32, vy: f32, ax: f32, ay: f32) -> SquareBody {
		SquareBody { 
			x, 
			y, 
			velocity: Vec2::new(mps_to_mpms(vx), mps_to_mpms(vy)), 
			acc: Vec2::new(mps_to_mpms(ax), mps_to_mpms(ay)) }
	}
}
