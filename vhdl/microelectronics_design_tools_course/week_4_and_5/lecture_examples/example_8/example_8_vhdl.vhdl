library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mini_alu is
    port
    (
        a, b: in std_logic_vector(3 downto 0);
        op: in std_logic_vector(1 downto 0);
        y: out std_logic_vector(3 downto 0)
    );
end entity mini_alu; 

architecture sel_arch of mini_alu is
    begin
        with op select
        y <= (a and b) when "00",
             (a or b) when "01",
             (std_logic_vector(unsigned(a) + unsigned(b))) when "10",
             (std_logic_vector(unsigned(a) - unsigned(b))) when others;
             
end architecture sel_arch;