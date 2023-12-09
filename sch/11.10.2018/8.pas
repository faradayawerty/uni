var n, i, s : integer;


function fact(x : integer);
begin
	if x = 0 then
		fact := 1
	else
		fact := x * fact(x - 1);
end;


begin
	readln(n);

	s := 0;

	for i := 1 to n do
		s := s + fact(i);

	writeln(s);
end.


