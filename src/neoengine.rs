use crate::{body::Moveable, conversions::time_ms};
use std::time::Instant;

#[derive(Debug)]
pub struct Neoengine {
	bodies: Vec<Box<dyn Moveable>>,
	timer: Instant,
	prev_frame: f32
}

#[allow(dead_code)]
#[derive(Debug)]
pub struct InitializationError;
pub struct ProcessingError;

impl Neoengine {
	pub fn init() -> Result<Neoengine, InitializationError> { 
		let mut n = Neoengine {
			bodies: vec![],
			timer: Instant::now(),
			prev_frame: 0.0
		};
		
		n.prev_frame = n.timer.elapsed().as_millis() as f32;
		
		println!("Current time is {}", n.prev_frame);

		Ok(n)
	}
	

	pub fn process(&mut self) -> Result<(),ProcessingError>{ 
		for body in self.bodies.iter_mut() {
			body.apply((self.timer.elapsed().as_millis() as f32) - self.prev_frame).expect("Failed to calculate.");
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
		println!("\nSTATS\nCurrent time: {}s", self.timer.elapsed().as_secs());
		
		for (index, body) in self.bodies.iter().enumerate() {
			print!("Body {}. | ", index);
			body.print();
		}
	}
}