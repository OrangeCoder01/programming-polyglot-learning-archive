library ieee;
use ieee.std_logic_1164.all;

entity mux41 is
    port
    (
        d: in std_logic_vector(3 downto 0);
        sel: in std_logic_vector(1 downto 0);
        y: out std_logic
    );
end entity mux41;

architecture rtl of mux41 is
    begin
        y <= d(0) when sel = "00" else
             d(1) when sel = "01" else
             d(2) when sel = "10" else
             d(3);
end rtl;

