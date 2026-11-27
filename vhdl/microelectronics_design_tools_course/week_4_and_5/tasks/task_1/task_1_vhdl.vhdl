library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity max_selector is
    port
    (
        a, b: in unsigned(1 downto 0);
        y: out unsigned (1 downto 0);
    );
end entity max_selector;


architecture ar_max_selector of max_selector is
    begin
        y <= a when (a > b )else b;
end architecture ar_max_selector;