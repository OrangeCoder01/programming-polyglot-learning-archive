library ieee;
use ieee.std_logic_1164.all;

entity encoder4to2 is
    port
    (
        d: in std_logic_vector(3 downto 0);
        y: out std_logic_vector(1 downto 0);
        valid: out std_logic
    );
end entity encoder4to2;

architecture rtl of encoder4to2 is
    begin
        process(d)
            begin
                y <= (others => '0');
                valid <= '0';
                case d is
                    when "0001" => 
                        y <= "00"; 
                        valid <= '1';

                    when "0010" => 
                        y <= "01"; 
                        valid <= '1';

                    when "0100" => 
                        y <= "10"; 
                        valid <= '1';

                    when "1000" => 
                        y <= "11"; 
                        valid <= '1';

                    when  others => 
                        y <= (others => 0);
                        valid <= '0';
                end case;
        end process;
end architecture rtl;
