import os
import time
import sys
from subprocess import check_output
from subprocess import PIPE, Popen

def git_root():
    return check_output(['git', 'rev-parse', '--show-toplevel'],
                        universal_newlines=True).rstrip()

def project_root():
    return "%s" % git_root()


class TsParser(object):
    """This object reflects TsParser executable."""
    parser = os.path.join(project_root(), 'tsparser')

    def __init__(self):
        self.proc = None

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        try:
            self.stop()
        except Exception as e:
            print("TsParser failed to stop: %r" % e)
        assert exc_type is None

    def start(self, **kwargs):
        """Start a process with arguments"""
        return self._start(**kwargs)

    def _start(self, **kwargs):
        """Internal function that forks a new process of executable with given
        arguments"""
        cmd = self.start_cmd(**kwargs)

        self.proc = Popen(cmd, stdout=PIPE, stderr=PIPE,
                          universal_newlines=True)
        out, err, exitcode = self.wait()

        print(out)
        sys.stderr.write(err)

        return exitcode, out, err

    def start_cmd(self, **kwargs):
        args = self._collect_args(**kwargs)
        cmd = [self.parser]
        cmd.extend(args)
        return cmd

    def wait(self, timeout=60):
        """Wait for the process to exit"""
        print("Waiting for parser process to exit")
        wait_start_time = time.time()
        out, err = self.proc.communicate(timeout=timeout * 1)
        print("Parser process done after ",
              round(time.time() - wait_start_time), " seconds")
        exitcode = self.proc.returncode
        return out, err, exitcode

    def _collect_args(self, input=None, extra_args=None):
        """Collects all the input arguments for the process."""
        args = []

        if input:
            args.append('--input')
            args.append(input)
        if extra_args:
            args.extend(extra_args)

        args = (str(a) for a in args)
        return args
