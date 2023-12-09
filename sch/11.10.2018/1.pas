var a : array[1..10] of integer;
var i : integer;


function divisors(n : integer) : integer; {англ. divisor -- делитель}
var j : integer;
begin
	divisors := 0; 
	
	for j := 1 to n do	
	begin 
		if n mod j = 0 then 
			divisors += 1; 
	end;
end;


begin
	for i := 1 to 10 do
	begin
		a[i] := random(100);
		write(a[i], ' ');
	end;
	writeln;

	for i := 1 to 10 do
	begin
		if divisors(a[i]) = 2 then {у простых чисел два делителя}
			write(a[i], ' ');
	end;
	writeln;
end.



