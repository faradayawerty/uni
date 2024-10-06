var x, p, i : integer;


function s(n : integer) : integer;
begin
	if n = 0 then 
		s := 0
	else 
		s := n + s(n-1);
end;


begin
	readln(x);

	p := 1;

	for i := 1 to x do
		p := p * s(i);

	writeln(p);
end.



