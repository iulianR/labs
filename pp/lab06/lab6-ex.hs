{-# LANGUAGE NoMonomorphismRestriction #-}
import Data.List
import Debug.Trace
import Test.QuickCheck

{-
Expresia `undefined` are orice tip dar nu poate fi evaluată.
-}

{-
1. (1p)
Construiți funcții simple pentru următoarele tipuri (completați definițiile):
-}
identity :: a -> a
identity = \a -> a

notF :: Bool -> Bool
notF True = False
notF _    = True

pair1 :: (a, b) -> a
pair1 = \(a, b) -> fst (a, b)

-- Verificare: check1 și check1QC
check1 = identity $ pair1 (notF False, undefined)
check1Prop :: Int -> Bool
check1Prop x = x == (identity $ pair1 (x, undefined))
check1QC = quickCheck check1Prop

{-
2. (2p)
Implementați funcția `unzip2`
-}
unzip2  :: [(a, b)] -> ([a], [b])
unzip2 x = (map fst x, map snd x)

-- Verificare: check2 și check2QC
check2 = unzip2 (zip [1, 2, 3] ["a", "b", "c"]) == ([1, 2, 3], ["a", "b", "c"])
check2Prop :: [Bool] -> [Bool] -> Property
check2Prop x y = (length x == length y) ==> unzip2 (zip x y) == (x, y)
check2QC = quickCheck check2Prop

{-
3. (2p)
Implementați, folosind obligatoriu list-comprehensions funcționala, `map`.
-}
mapLC :: (a -> b) -> [a] -> [b]
mapLC f list = [f x | x <- list]

-- Verificare: check3, check3QC și check3QC2
check3 = mapLC (* 2) [1, 2, 3] == [2, 4, 6]
check3Prop :: [Int] -> Bool
check3Prop x = mapLC (* 2) x == map (* 2) x
check3QC = quickCheck check3Prop
check3Prop2 :: [Bool] -> Bool
check3Prop2 x = mapLC (\x -> [x, not x]) x == map (\x -> [x, not x]) x
check3QC2 = quickCheck check3Prop2

{-
4. (1p)
Implementați, folosind obligatoriu list-comprehensions funcționala, `filter`.
-}
filterLC :: (a -> Bool) -> [a] -> [a]
filterLC f list = [x | x <- list, f x == True]

-- Verificare: check4, check4QC și check4QC2
check4 = filterLC (\x -> x `mod` 2 == 0) [1, 2, 4] == [2, 4]
check4Prop :: [Int] -> Bool
check4Prop x = filterLC (\x -> x `mod` 2 == 0) x == filter (\x -> x `mod` 2 == 0) x
check4QC = quickCheck check4Prop
check4Prop2 :: [Bool] -> Bool
check4Prop2 x = filterLC id x == filter id x
check4QC2 = quickCheck check4Prop2

{-
5. (1p)
Implementați o funcție ce calculează cmmdc-ul a două numere pozitive.
-}
cmmdc :: Integer -> Integer -> Integer
cmmdc x y = if y == 0 then x else cmmdc y (mod x y)

-- Verificare: check5 și check5QC
check5 = and
  [ cmmdc 6 4 == 2
  , cmmdc 6 12 == 6
  , cmmdc 6 9 == 3
  , cmmdc 6 7 == 1
  ]
check5Prop x y = (x > 0 && y > 0) ==> let c = cmmdc x y in and [x `mod` c == 0, y `mod` c == 0]
check5QC = quickCheck check5Prop

{-
6. (1p)
Folosind list-comprehensions traduceți în Haskell mulțimea,
 unde (x, y) este cmmdc al x și y

  { (a, b, c) | a<- [1..10], b<-[2..10], b > a, c = (a, b)}
-}
multime = [(a, b, cmmdc a b) | a <- [1..10], b <- [2..10], b > a]

-- Verificare: check6
answer = [(1,2,1),(1,3,1),(1,4,1),(1,5,1),(1,6,1),(1,7,1),(1,8,1),(1,9,1),(1,10,1),(2,3,1),(2,4,2),(2,5,1),(2,6,2),(2,7,1),(2,8,2),(2,9,1),(2,10,2),(3,4,1),(3,5,1),(3,6,3),(3,7,1),(3,8,1),(3,9,3),(3,10,1),(4,5,1),(4,6,2),(4,7,1),(4,8,4),(4,9,1),(4,10,2),(5,6,1),(5,7,1),(5,8,1),(5,9,1),(5,10,5),(6,7,1),(6,8,2),(6,9,3),(6,10,2),(7,8,1),(7,9,1),(7,10,1),(8,9,1),(8,10,2),(9,10,1)]
check6 = answer == sort multime

{-
7. (2p)
Definiți o funcție care întoarce primul cuvânt dintr-un string (cuvintele 
sunt delimitate de un spațiu.
-}
firstWord :: String -> String
firstWord input = head (words input)

-- Verificare: check7
check7 = firstWord "Ce laborator frumos!" == "Ce"

{-
8. (BONUS, 3p)
String substitution. Definiți `subst` care înlocuiește cuvinte, astfel încât:

  subst "frumos" "destept" "Ce laborator frumos !" = "Ce laborator destept !"

Cuvintele sunt delimitate de spațiu.
  
Hint: s-ar putea să aveți nevoie de funcții auxiliare. Puteți folosi `words`
pentru a obține cuvintele din frază și `unwords` sau `++` pentru a obține
frază din cuvinte.
-}

subst :: String -> String -> String -> String
subst what new input = unwords (map (\x -> if x == what then new else x) (words input))

-- Verificare: check8
check8 = subst "frumos" "destept" "Ce laborator frumos !" == "Ce laborator destept !"

{-
9. (BONUS, 2p)
Implementați `increasingPairs` (din `lab6-doc.hs`) astfel încât să se genereze
elementele în ordinea crescătoare a sumei valorilor din pereche.
-}
naturals = [x | x <- [0 ..]]
increasingPairs = [(x, y) | z <- naturals, x <- [0.. z `div` 2], let y = z - x, x < y]

-- Verificare: check9
check9 = take 10 increasingPairs == [(0,1),(0,2),(0,3),(1,2),(0,4),(1,3),(0,5),(1,4),(2,3),(0,6)]

{-
Helpers for testing :)
-}
simpleTestsPassed = and [check1, check2, check3, check4, check5, check6, check7, check8, check9]
quickChecks = sequence_ [check1QC, check2QC, check3QC, check3QC2, check4QC, check4QC2, check5QC]
