use crate::body::Moveable;
use std::time::{Instant};

#[derive(Debug)]
pub struct Neoengine {
	bodies: Vec<Box<dyn Moveable>>,
	timer: Instant
}

#[allow(dead_code)]
#[derive(Debug)]
pub struct InitializationError;

impl Neoengine {
	pub fn init() -> Result<Neoengine, InitializationError> { 
		let n = Neoengine {
			bodies: vec![],
			timer: Instant::now()
		};
		
		Ok(n)
	}
	
	pub fn process(&self) -> Result<(),()>{ 
		for body in self.bodies.iter() {
			body.print();
			println!("Time elapsed: {}", self.timer.elapsed().as_secs());
		}
		Ok(())
	}

	pub fn append_body(&mut self, body: Box<dyn Moveable>) -> usize {
		self.bodies.append(&mut vec![body]);
		self.bodies.len()
	}
	
	pub fn now(&self) -> u64{
		self.timer.elapsed().as_secs()
	}
}