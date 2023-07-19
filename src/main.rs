mod neoengine;
mod vector;
mod body;

use std::thread::sleep;

use neoengine::Neoengine;
use std::time::Duration;
fn main() {
    println!("Hello, world!");
    let engine: Neoengine = Neoengine::init().unwrap();
    loop {
        sleep(Duration::new(2,0));
        println!("{}", engine.now());
    }
}
