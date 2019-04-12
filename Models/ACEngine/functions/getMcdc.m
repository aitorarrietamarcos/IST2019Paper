function [mcdc] = getMcdc(activationArray,data_objects,system)
    init = 0;
    if(sum(activationArray) == 0)
       mcdc = 0; 
    else
        for i=1:size(activationArray,2)
            if(activationArray(i) == 1)
                if init == 0
                    covdata = data_objects{i};
                    init = 1;
                else
                    covdata = data_objects{i} + covdata;
                end
            end
        end
        blk_handle = get_param(system,'Handle');

        mcdcdata = mcdcinfo(covdata,blk_handle);
        mcdc = mcdcdata(1)/mcdcdata(2);
    end

end

