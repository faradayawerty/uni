var n, i, s : integer;


function p(x, y : integer) : integer; 
begin
	if y = 0 then
		p := 1
	else
		p := x * p(x, y - 1);
end;


begin
	readln(n);
	
	s := 0;

	for i := 0 to n do 
		s := s +  p(2, i);

	writeln(s);
end.


