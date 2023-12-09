var s, s1, s2 : string;
var i : integer;

begin
	readln(s1);
	readln(s2);
	s := '';

	for i := 1 to length(s1) do
		s += s1[i] + s2[i];

	writeln(s);
end.

