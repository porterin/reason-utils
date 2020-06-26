exception Empty_List;
exception InternalServerError;
exception NotAuthenticated;
exception Forbidden;
exception UnprocessedEntity;
exception RequestTimedout;

let fromString = (exn: string) => {
  switch (exn) {
  | "Exception.Empty_List" => Empty_List
  | "Exception.InternalServerError" => InternalServerError
  | "Exception.NotAuthenticated" => NotAuthenticated
  | "Exception.Forbidden" => Forbidden
  | "Exception.UnprocessedEntity" => UnprocessedEntity
  | "Exception.RequestTimedout" => RequestTimedout
  | _ => raise(Not_found)
  };
};

module ExceptionToErrorTextMap = {
  let getErrorMessage = (exn: exn) => {
    switch (exn) {
    | Empty_List => "The list is empty"
    | InternalServerError => "Something went wrong"
    | NotAuthenticated => "Authentication Failure"
    | Forbidden => "The requested resource is not available for the user to view"
    | UnprocessedEntity => "Please check your form inputs and try again"
    | _ => raise(Not_found)
    };
  };
};

module PromiseToExceptionMap = {
  external errorToPair: Js.Promise.error => (string, int) = "%identity";

  let getException = (error: Js.Promise.error): exn => {
    error |> errorToPair |> fst |> fromString;
  };
};
