library ieee;
use ieee.std_logic_1164.all;

entity mux41 is
    port
    (
        a, b, c, d: in std_logic;
        sel: in sttd_logic_vector(1 downto 0);
        y : out std_logic
    );
end entity mux41;

architecture sel_arch of mux41 is
    begin
        with sel select
        y <= a when "00",
             b when "01",
             c when "10",
             d when "11".
             'X' when others;
end architecture sel_arch;