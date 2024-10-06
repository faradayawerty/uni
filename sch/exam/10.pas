var i : integer;

function digit_sum(n : integer) : integer;
begin
	if n = 0 then
		digit_sum := 0
	else
		digit_sum := n mod 10 + digit_sum(n div 10);
end;

begin
	for i := 100 to 999 do
		if (i mod 5 = 0) and (digit_sum(i) mod 5 = 0) then
			writeln(i);
end.

