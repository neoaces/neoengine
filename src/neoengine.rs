use crate::{body::Moveable, conversions::mil_to_secs};
use std::time::{Instant};

#[derive(Debug)]
pub struct Neoengine {
	bodies: Vec<Box<dyn Moveable>>,
	timer: Instant,
	prev_frame: f32
}

#[allow(dead_code)]
#[derive(Debug)]
pub struct InitializationError;

impl Neoengine {
	pub fn init() -> Result<Neoengine, InitializationError> { 
		let mut n = Neoengine {
			bodies: vec![],
			timer: Instant::now(),
			prev_frame: 0.0
		};
		
		n.prev_frame = mil_to_secs(n.timer);

		Ok(n)
	}
	
	pub fn process(&mut self) -> Result<(),()>{ 
		for body in self.bodies.iter_mut() {
			body.apply(((self.timer.elapsed().as_millis() as f32) - self.prev_frame) / 1000.0).expect("Failed to calculate.");
			println!("Time elapsed: {}", self.timer.elapsed().as_secs());
		}

		self.prev_frame = self.timer.elapsed().as_millis() as f32;
		
		Ok(())
	}

	pub fn append_body(&mut self, body: Box<dyn Moveable>) -> usize {
		self.bodies.append(&mut vec![body]);
		self.bodies.len()
	}
	
	pub fn now(&self) -> u64 {
		self.timer.elapsed().as_secs()
	}

	pub fn stat(&self) {
		println!("\nSTATS\nCurrent time: {} secs", self.timer.elapsed().as_secs());
		
		for (index, body) in self.bodies.iter().enumerate() {
			print!("Body {}. ", index);
			body.print();
		}
	}
}