var radiuses : array[1..8] of longint = (2439, 6051, 6371, 3389, 69911, 58232, 25362, 24622);
var i : integer;


function area(r : real) : real; {англ. area -- площадь}
begin
	area := 4*pi*r*r;
end;


function circumference(r : real) : real; {англ. circumference -- длина окружности}
begin
	circumference := 2*pi*r;
end;


begin
	for i := 1 to 8 do
		writeln(area(radiuses[i]), ' ', circumference(radiuses[i]));
end.


