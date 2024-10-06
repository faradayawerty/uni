var s, n, m, i : integer;


function divisors(x : integer) : integer; {англ. divisors -- делители}
var j : integer;
begin
	divisors := 0;

	for j := 1 to x do
	begin
		if x mod j = 0 then
			divisors += 1;
	end;
end;


begin
	readln(n);
	readln(m);

	s := 0;

	for i := n to m do
	begin 
		if divisors(i) = 2 then {простые числа имеют ровно два делителя}
			s := s + i*i;
	end;

	writeln(s);
end.


