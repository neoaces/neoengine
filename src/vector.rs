use std::ops::{Mul, Add};

use crate::{body::CalculationError, conversions::secs_to_mil};

#[derive(Debug, PartialEq, Clone, Copy)]
pub struct Vec2 {
    pub x: f32,
    pub y: f32,
}

impl Vec2 {
    pub fn new(nx: f32, ny: f32) -> Vec2 {
        Vec2 { 
            x: nx,
            y: ny
        }
    }
    pub fn new_ms(x: f32, y: f32) -> Vec2 {
        Vec2 { 
            x, y
        }
    }

    pub fn scale(&mut self, factor: f32) -> Result<(), CalculationError> {
        self.x *= factor;
        self.y *= factor;
        Ok(())
    }

    pub fn magnitude(&self) -> f32 {
        ((self.x.powf(2.0)) + (self.y.powf(2.0))).sqrt()
    }

}

impl Mul for Vec2 {
    type Output = Vec2;
    fn mul(self, rhs: Self) -> Self::Output {
        Vec2::new(self.x * rhs.x, self.y * rhs.y)
    }
}

impl Add for Vec2 {
    type Output = Vec2;
    fn add(self, rhs: Self) -> Self::Output {
        Vec2::new(self.x + rhs.x, self.y + rhs.y)
    }
}