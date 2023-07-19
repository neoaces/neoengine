use crate::vector::Vector;
use core::fmt::Debug;

pub trait Moveable {
	fn apply(&self, ms: f32);
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
	x: f32,
	y: f32,
	velocity: Vector
}

impl SquareBody {
	fn print(&self) {
		println!("{:#?}", self);
	}
	
	fn to_string(&self) {
		self.x.to_string();
	}
}
