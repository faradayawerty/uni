var AB, BC, AC, CM : real; 


function m(a, b, c : real) : real;
begin
	m := 0.5 * sqrt(2*a*a + 2*b*b - c*c);
end;


begin
	readln(AB);
	readln(BC);
	readln(AC);

	CM := m(AB, BC, AC);
	writeln(CM);
end.


