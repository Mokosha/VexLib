{-# LANGUAGE MultiParamTypeClasses #-}

data Vector2Type t = Vector2 t t
data Vector3Type t = Vector3 t t t
data Vector4Type t = Vector4 t t t t

-------------------------------------------------------------------------
-- Vector2 functions...
instance (Eq t) => Eq (Vector2Type t) where
  (Vector2 x1 y1) == (Vector2 x2 y2) = (x1 == x2) && (y1 == y2)

instance (Show t) => Show (Vector2Type t) where
  show (Vector2 x y) = "<" ++ show x ++ ", " ++ show y ++ ">"

instance (Num t) => Num (Vector2Type t) where
  -- Addition --
  (Vector2 x1 y1) + (Vector2 x2 y2) = Vector2 (x1+x2) (y1+y2)

  -- Subtraction --
  (Vector2 x1 y1) - (Vector2 x2 y2) = Vector2 (x1-x2) (y1-y2)

  -- Piecewise Multiplication
  (Vector2 x1 y1) * (Vector2 x2 y2) = Vector2 (x1*x2) (y1*y2)

  -- Negate --
  negate (Vector2 x y) = Vector2 (negate x) (negate y)

  -- Absolute Value --
  abs (Vector2 x y) = Vector2 (abs x) (abs y)

  -- Signum --
  signum (Vector2 x y) = Vector2 (signum x) (signum y)

  -- From Integer --
  fromInteger i = Vector2 (fromInteger i) (fromInteger i)

instance (Fractional t) => Fractional (Vector2Type t) where
  -- Division --
  (Vector2 x y) / (Vector2 x' y') = Vector2 (x/x') (y/y')

  -- From Rational --
  fromRational r = Vector2 (fromRational r) (fromRational r)

-------------------------------------------------------------------------
-- Vector3 functions...
instance (Eq t) => Eq (Vector3Type t) where
  (Vector3 x y z) == (Vector3 x' y' z') = (x == x') && (y == y') && (z == z')

instance (Show t) => Show (Vector3Type t) where
  show (Vector3 x y z) = "<" ++ show x ++ ", " ++ show y ++ ", " ++ show z ++ ">"

instance (Num t) => Num (Vector3Type t) where
  -- Addition --
  (Vector3 x y z) + (Vector3 x' y' z') = Vector3 (x+x') (y+y') (z+z')

  -- Subtraction --
  (Vector3 x y z) - (Vector3 x' y' z') = Vector3 (x-x') (y-y') (z-z') 

  -- Piecewise Multiplication
  (Vector3 x y z) * (Vector3 x' y' z') = Vector3 (x*x') (y*y') (z*z')

  -- Negate --
  negate (Vector3 x y z) = Vector3 (negate x) (negate y) (negate z)

  -- Absolute Value --
  abs (Vector3 x y z) = Vector3 (abs x) (abs y) (abs z)

  -- Signum --
  signum (Vector3 x y z) = Vector3 (signum x) (signum y) (signum z)

  -- From Integer --
  fromInteger i = Vector3 (fromInteger i) (fromInteger i) (fromInteger i)

instance (Fractional t) => Fractional (Vector3Type t) where
  -- Division --
  (Vector3 x y z) / (Vector3 x' y' z') = Vector3 (x/x') (y/y') (z/z')

  -- From Rational --
  fromRational r = Vector3 (fromRational r) (fromRational r) (fromRational r)

-------------------------------------------------------------------------
-- Vector4 functions...
instance (Eq t) => Eq (Vector4Type t) where
  (Vector4 x y z w) == (Vector4 x' y' z' w') = (x == x') && (y == y') && (z == z') && (w == w')

instance (Show t) => Show (Vector4Type t) where
  show (Vector4 x y z w) = "<" ++ show x ++ ", " ++ show y ++ ", " ++ show z ++ ", " ++ show w ++ ">"

instance (Num t) => Num (Vector4Type t) where
  -- Addition --
  (Vector4 x y z w) + (Vector4 x' y' z' w') = Vector4 (x+x') (y+y') (z+z') (w+w')

  -- Subtraction --
  (Vector4 x y z w) - (Vector4 x' y' z' w') = Vector4 (x-x') (y-y') (z-z') (w-w')

  -- Piecewise Multiplication
  (Vector4 x y z w) * (Vector4 x' y' z' w') = Vector4 (x*x') (y*y') (z*z') (w*w')

  -- Negate --
  negate (Vector4 x y z w) = Vector4 (negate x) (negate y) (negate z) (negate w)

  -- Absolute Value --
  abs (Vector4 x y z w) = Vector4 (abs x) (abs y) (abs z) (abs w)

  -- Signum --
  signum (Vector4 x y z w) = Vector4 (signum x) (signum y) (signum z) (signum w)

  -- From Integer --
  fromInteger i = Vector4 (fromInteger i) (fromInteger i) (fromInteger i) (fromInteger i)

instance (Fractional t) => Fractional (Vector4Type t) where
  -- Division --
  (Vector4 x y z w) / (Vector4 x' y' z' w') = Vector4 (x/x') (y/y') (z/z') (w/w')

  -- From Rational --
  fromRational r = Vector4 (fromRational r) (fromRational r) (fromRational r) (fromRational r)

type Vec2f = Vector2Type Float
type Vec3f = Vector3Type Float
type Vec4f = Vector4Type Float

type Vec2d = Vector2Type Double
type Vec3d = Vector3Type Double
type Vec4d = Vector4Type Double
