define vds
    if $argc == 1
        $arg0
    else
    	if $argc == 2
    		$arg0 $arg1
    	else
    		if $argc == 3
    			$arg0 $arg1 $arg2
    		else
    			if $argc == 4
    				$arg0 $arg1 $arg2 $arg3
    			else
    				if $argc == 5
    					$arg0 $arg1 $arg2 $arg3 $arg4
					else
						if $argc == 6
							$arg0 $arg1 $arg2 $arg3 $arg4 $arg5
						else
							if $argc == 7
								$arg0 $arg1 $arg2 $arg3 $arg4 $arg5 $arg6
							else
								if $argc == 8
									$arg0 $arg1 $arg2 $arg3 $arg4 $arg5 $arg6 $arg7
								else
									if $argc == 9
										$arg0 $arg1 $arg2 $arg3 $arg4 $arg5 $arg6 $arg7 $arg8
									else
										if $argc == 10
											$arg0 $arg1 $arg2 $arg3 $arg4 $arg5 $arg6 $arg7 $arg8 $arg9
										else
										end
									end
								end
							end
						end
					end
				end
			end
		end
    end
    call VDS_SHOW()
end
