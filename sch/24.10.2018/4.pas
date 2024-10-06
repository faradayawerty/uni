var s : string;


function flip(s : string) : string;
var i : integer;
begin
	flip := '';

	for i := length(s) downto 1 do
		flip += s[i];
end;


begin
	readln(s);
	writeln(s = flip(s));
end.
