library ieee;
use ieee.std_logic_1164.all;

entity mux21 is
    port
    (
        a, b: in std_logic;
        sel: in std_logic;
        y: out std_logic;
    );
end entity mux21;

architecture rtl of mux21 is
    begin
        y <= a when sel = '0' else b;
end architecture rtl;