load('PROJECT_WORKSPACE.mat', 'T')
load('PROJECT_WORKSPACE.mat', 'trainedModel')
yfit = trainedModel.predictFcn(T);
disp(yfit);

yact = readtable('ActualTesingResult.xlsx');
yact1 = yact.P;
disp((yact1));

%ACCURACY DATA
% Calculate the mean of the actual values
meanActual = mean(yact1);
% Calculate the Residual Sum of Squares (RSS)
RSS = sum((yact1 - yfit).^2);
% Calculate the Total Sum of Squares (TSS)
TSS = sum((yact1 - meanActual).^2);
% Calculate R^2
R2 = 1 - (RSS / TSS);
% Display R^2
disp(['R^2 (Coefficient of Determination): ', num2str(R2)]);

% RMSE
% Calculate the residuals (errors)
residuals = yact1 - yfit;
% Calculate the Mean Squared Error (MSE)
MSE = mean(residuals.^2);
% Calculate the Root Mean Squared Error (RMSE)
RMSE = sqrt(MSE);
% Display RMSE
disp(['RMSE (Root Mean Squared Error): ', num2str(RMSE)]);

