mod neoengine;
mod vector;
mod body;
mod conversions;
mod test;

use std::thread::sleep;
use crate::{body::SquareBody, vector::Vec2};
use neoengine::Neoengine;
use std::time::Duration;
fn main() {
    println!("Hello, world!");
    let mut engine: Neoengine = Neoengine::init().unwrap();
    
    engine.append_body(Box::new(SquareBody::new(
        0.0, 0.0, 1.0, 0.0, 1.0, 0.0
    )));

    loop {
        // sleep(Duration::new(0, 500000000));
        let _ = engine.process();
        engine.stat();
        // println!("{}", engine.now());
    }
}
