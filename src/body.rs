use crate::vector::Vec2;
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
	pub velocity: Vec2
}

impl SquareBody {
	fn to_string(&self) {
		self.x.to_string();
	}
}

#[derive(Debug)]
pub struct CalculationError;

impl Moveable for SquareBody {
	fn apply(&mut self, ms: f32) -> Result<(), CalculationError> {
		// X
		self.x += self.velocity.x * ms;
		// Y
		self.y += self.velocity.y * ms;
		Ok(())
	}

	fn print(&self) {
		println!("Velocity, x: {}, y: {}", self.x, self.y);
	}

	fn to_string(&self) -> String {
		let x  = format!("Velocity, x: {}, y: {}", self.x, self.y);
		x
	}	
}
