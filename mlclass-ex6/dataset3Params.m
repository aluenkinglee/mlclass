function [C, sigma] = dataset3Params(X, y, Xval, yval)
%EX6PARAMS returns your choice of C and sigma for Part 3 of the exercise
%where you select the optimal (C, sigma) learning parameters to use for SVM
%with RBF kernel
%   [C, sigma] = EX6PARAMS(X, y, Xval, yval) returns your choice of C and 
%   sigma. You should complete this function to return the optimal C and 
%   sigma based on a cross-validation set.
%

% You need to return the following variables correctly.
C = 1;
sigma = 0.1;

% ====================== YOUR CODE HERE ======================
% Instructions: Fill in this function to return the optimal C and sigma
%               learning parameters found using the cross validation set.
%               You can use svmPredict to predict the labels on the cross
%               validation set. For example, 
%                   predictions = svmPredict(model, Xval);
%               will return the predictions on the cross validation set.
%
%  Note: You can compute the prediction error using 
%        mean(double(predictions ~= yval))
%

% FOUND THE OPTIMAL values of this program

% cset = [0.01; 0.03; 0.1; 0.3; 1; 3; 10; 30];
% sset = [0.01; 0.03; 0.1; 0.3; 1; 3; 10; 30];

% n = size(cset)(1);

% model= svmTrain(X, y, C, @(x1, x2) gaussianKernel(x1, x2, sigma));
% predictions = svmPredict(model, Xval);
% minum = mean(double(predictions ~= yval));

% fprintf('Initial Program. Press enter to continue.\n');
% C
% sigma
% minum
% visualizeBoundary(X, y, model);
% pause;

% Iteration = 0;
% % Test all the possibles.
% for i = 1: n
% 	for j = 1: n
% 		Iteration += 1;
% 		fprintf('Iteration %d.\n', Iteration);

% 		c = cset(i);
% 		s = sset(j);

% 		model= svmTrain(X, y, c, @(x1, x2) gaussianKernel(x1, x2, s));
% 		predictions = svmPredict(model, Xval);
% 		temp = mean(double(predictions ~= yval));

% 		% found a local optimal values, assign to the parameters and visualize.
% 		if temp < minum
% 			fprintf('Found optimal values. Press enter to continue.\n');
% 			C = c
% 			sigma = s
% 			minum = temp
% 			visualizeBoundary(X, y, model);
% 			pause;
% 		end
% 	end
% end

% =========================================================================

end
