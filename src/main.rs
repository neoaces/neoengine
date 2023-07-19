mod neoengine;
mod vector;
mod body;
mod conversions;

use std::thread::sleep;
use crate::{body::SquareBody, vector::Vec2};
use neoengine::Neoengine;
use std::time::Duration;
fn main() {
    println!("Hello, world!");
    let mut engine: Neoengine = Neoengine::init().unwrap();
    engine.append_body(Box::new(SquareBody {
        x: 0.0,
        y: 0.0,
        velocity: Vec2::new(1.0, 0.0, 0.0)
    }));

    engine.append_body(Box::new(SquareBody {
        x: 0.0,
        y: 0.0,
        velocity: Vec2::new(2.0, 0.0, 0.0)
    }));

    loop {
        sleep(Duration::new(1,0));
        let _ = engine.process();
        engine.stat();
        // println!("{}", engine.now());
    }
}
