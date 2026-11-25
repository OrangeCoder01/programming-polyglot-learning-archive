library ieee;
use ieee.std_logic_1164.all;
entity broken_gate is
        port
        (
            a, b: in std_logic;
            y1, y2: out std_logic
        );

end entity broken_gate;

architecture rtl of broken_gate is
    signal tmp: std_logic;
    begin
        tmp <= a and b;
        y1 <= tmp;
        y2 <= a or b;
end architecture rtl;
